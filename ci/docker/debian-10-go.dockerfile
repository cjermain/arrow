# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

ARG arch=amd64
ARG go=1.15
FROM ${arch}/golang:${go}-buster

RUN GO111MODULE=on go install honnef.co/go/tools/cmd/staticcheck@latest

# TODO(kszucs):
# 1. add the files required to install the dependencies to .dockerignore
# 2. copy these files to their appropriate path
# 3. download and compile the dependencies
