/*
 * Copyright (c) 2002-2018 "Neo4j,"
 * Neo4j Sweden AB [http://neo4j.com]
 *
 * This file is part of Neo4j.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SEABOLT_ADDRESSING_H
#define SEABOLT_ADDRESSING_H

#include "bolt-public.h"

/**
 * The address of a Bolt server. This can carry both the original host
 * and port details, as supplied by the application, as well as one or
 * more resolved IP addresses and port number.
 */
typedef struct BoltAddress BoltAddress;

/**
 * Create a new address structure for a given host and port. No name
 * resolution is carried out on creation so this simply initialises
 * the original host and port details and zeroes out the remainder
 * of the structure.
 *
 * @param host host name for this address, e.g. "www.example.com"
 * @param port port name or numeric string, e.g. "7687" or "http"
 * @return pointer to a new BoltAddress
 */
SEABOLT_EXPORT struct BoltAddress* BoltAddress_create(const char* host, const char* port);

SEABOLT_EXPORT const char* BoltAddress_host(BoltAddress* address);

SEABOLT_EXPORT const char* BoltAddress_port(BoltAddress* address);
/**
 * Resolve the original host and port into one or more IP addresses and
 * a port number. This can be carried out more than once on the same
 * address. Any newly-resolved addresses will replace any previously stored.
 *
 * @param address pointer to a BoltAddress
 * @param n_resolved pointer to an int value where number of resolved addresses will be saved
 * @return status of the internal getaddrinfo call
 */
SEABOLT_EXPORT int32_t BoltAddress_resolve(BoltAddress* address, int32_t* n_resolved, struct BoltLog* log);

/**
 * Copy the textual representation of a resolved host IP address into a buffer.
 *
 * If successful, AF_INET or AF_INET6 is returned depending on the address
 * family. If unsuccessful, -1 is returned. Failure may be a result of a
 * system problem or because the supplied buffer is too small for the address.
 *
 * @param address pointer to a resolved BoltAddress structure
 * @param index index of the resolved IP address
 * @param buffer buffer in which to write the address representation
 * @param buffer_size size of the buffer
 * @return address family (AF_INET or AF_INET6) or -1 on error
 */
SEABOLT_EXPORT int32_t
BoltAddress_copy_resolved_host(BoltAddress* address, int32_t index, char* buffer, uint64_t buffer_size);

/**
 * Destroy an address structure and deallocate any associated memory.
 *
 * @param address pointer to a BoltAddress structure
 */
SEABOLT_EXPORT void BoltAddress_destroy(BoltAddress* address);

#endif // SEABOLT_ADDRESSING_H
