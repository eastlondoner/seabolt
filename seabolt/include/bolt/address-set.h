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
#ifndef SEABOLT_ALL_ADDRESS_SET_H
#define SEABOLT_ALL_ADDRESS_SET_H

#include "address.h"

struct BoltAddressSet {
    int size;
    struct BoltAddress** elements;
};

#define SIZE_OF_ADDRESS_SET sizeof(struct BoltAddressSet)
#define SIZE_OF_ADDRESS_SET_PTR sizeof(struct BoltAddressSet*)

PUBLIC struct BoltAddressSet* BoltAddressSet_create();

PUBLIC void BoltAddressSet_destroy(struct BoltAddressSet* set);

PUBLIC int BoltAddressSet_size(struct BoltAddressSet* set);

PUBLIC int BoltAddressSet_index_of(struct BoltAddressSet* set, struct BoltAddress address);

PUBLIC int BoltAddressSet_add(struct BoltAddressSet* set, struct BoltAddress address);

PUBLIC int BoltAddressSet_remove(struct BoltAddressSet* set, struct BoltAddress address);

PUBLIC void BoltAddressSet_replace(struct BoltAddressSet* destination, struct BoltAddressSet* source);

PUBLIC void BoltAddressSet_add_all(struct BoltAddressSet* destination, struct BoltAddressSet* source);

#endif //SEABOLT_ALL_ADDRESS_SET_H