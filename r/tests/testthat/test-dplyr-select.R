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

skip_if(on_old_windows())

library(dplyr, warn.conflicts = FALSE)
library(stringr)

tbl <- example_data

test_that("Empty select returns no columns", {
  compare_dplyr_binding(
    .input %>% select() %>% collect(),
    tbl
  )
})
test_that("Empty select still includes the group_by columns", {
  expect_message(
    compare_dplyr_binding(
      .input %>% group_by(chr) %>% select() %>% collect(),
      tbl
    ),
    "Adding missing grouping variables"
  )
})

test_that("select/rename", {
  compare_dplyr_binding(
    .input %>%
      select(string = chr, int) %>%
      collect(),
    tbl
  )
  compare_dplyr_binding(
    .input %>%
      rename(string = chr) %>%
      collect(),
    tbl
  )
  compare_dplyr_binding(
    .input %>%
      rename(strng = chr) %>%
      rename(other = strng) %>%
      collect(),
    tbl
  )
})

test_that("select/rename with selection helpers", {

  # TODO: add some passing tests here

  expect_error(
    compare_dplyr_binding(
      .input %>%
        select(where(is.numeric)) %>%
        collect(),
      tbl
    ),
    "Unsupported selection helper"
  )
})

test_that("filtering with rename", {
  compare_dplyr_binding(
    .input %>%
      filter(chr == "b") %>%
      select(string = chr, int) %>%
      collect(),
    tbl
  )
  compare_dplyr_binding(
    .input %>%
      select(string = chr, int) %>%
      filter(string == "b") %>%
      collect(),
    tbl
  )
})

test_that("relocate", {
  df <- tibble(a = 1, b = 1, c = 1, d = "a", e = "a", f = "a")
  compare_dplyr_binding(
    .input %>% relocate(f) %>% collect(),
    df,
  )
  compare_dplyr_binding(
    .input %>% relocate(a, .after = c) %>% collect(),
    df,
  )
  compare_dplyr_binding(
    .input %>% relocate(f, .before = b) %>% collect(),
    df,
  )
  compare_dplyr_binding(
    .input %>% relocate(a, .after = last_col()) %>% collect(),
    df,
  )
  compare_dplyr_binding(
    .input %>% relocate(ff = f) %>% collect(),
    df,
  )
})

test_that("relocate with selection helpers", {
  df <- tibble(a = 1, b = 1, c = 1, d = "a", e = "a", f = "a")
  compare_dplyr_binding(
    .input %>% relocate(any_of(c("a", "e", "i", "o", "u"))) %>% collect(),
    df
  )
  compare_dplyr_binding(
    .input %>% relocate(where(is.character)) %>% collect(),
    df
  )
  compare_dplyr_binding(
    .input %>% relocate(a, b, c, .after = where(is.character)) %>% collect(),
    df
  )
  compare_dplyr_binding(
    .input %>% relocate(d, e, f, .before = where(is.numeric)) %>% collect(),
    df
  )
  # works after other dplyr verbs
  compare_dplyr_binding(
    .input %>%
      mutate(c = as.character(c)) %>%
      relocate(d, e, f, .after = where(is.numeric)) %>%
      collect(),
    df
  )
})
