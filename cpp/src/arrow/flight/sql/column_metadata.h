// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <string>

#include "arrow/util/key_value_metadata.h"

namespace arrow {
namespace flight {
namespace sql {

/// \brief Helper class to set column metadata.
class ColumnMetadata {
 private:
  std::shared_ptr<arrow::KeyValueMetadata> metadata_map_;
  explicit ColumnMetadata(std::shared_ptr<arrow::KeyValueMetadata> metadata_map);

 public:
  class ColumnMetadataBuilder;

  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kCatalogName;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kSchemaName;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kTableName;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kPrecision;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kScale;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kIsAutoIncrement;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kIsCaseSensitive;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kIsReadOnly;
  /// \brief Constant variable to hold the value of the key that
  ///        will be used in the KeyValueMetadata class.
  static const char* kIsSearchable;

  /// \brief Static initializer.
  static ColumnMetadataBuilder Builder();

  /// \brief  Return the catalog name set in the KeyValueMetadata.
  /// \return The catalog name.
  arrow::Result<std::string> GetCatalogName() const;

  /// \brief  Return the schema name set in the KeyValueMetadata.
  /// \return The schema name.
  arrow::Result<std::string> GetSchemaName() const;

  /// \brief  Return the table name set in the KeyValueMetadata.
  /// \return The table name.
  arrow::Result<std::string> GetTableName() const;

  /// \brief  Return the precision set in the KeyValueMetadata.
  /// \return The precision.
  arrow::Result<int32_t> GetPrecision() const;

  /// \brief  Return the scale set in the KeyValueMetadata.
  /// \return The scale.
  arrow::Result<int32_t> GetScale() const;

  /// \brief  Return the IsAutoIncrement set in the KeyValueMetadata.
  /// \return The IsAutoIncrement.
  arrow::Result<bool> GetIsAutoIncrement() const;

  /// \brief  Return the IsCaseSensitive set in the KeyValueMetadata.
  /// \return The IsCaseSensitive.
  arrow::Result<bool> GetIsCaseSensitive() const;

  /// \brief  Return the IsReadOnly set in the KeyValueMetadata.
  /// \return The IsReadOnly.
  arrow::Result<bool> GetIsReadOnly() const;

  /// \brief  Return the IsSearchable set in the KeyValueMetadata.
  /// \return The IsSearchable.
  arrow::Result<bool> GetIsSearchable() const;

  /// \brief  Return the KeyValueMetadata.
  /// \return The KeyValueMetadata.
  const std::shared_ptr<arrow::KeyValueMetadata>& metadata_map() const;

  /// \brief A builder class to construct the ColumnMetadata object.
  class ColumnMetadataBuilder {
   public:
    friend class ColumnMetadata;

    /// \brief Set the catalog name in the KeyValueMetadata object.
    /// \param[in] catalog_name The catalog name.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& CatalogName(std::string& catalog_name);

    /// \brief Set the schema_name in the KeyValueMetadata object.
    /// \param[in] schema_name The schema_name.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& SchemaName(std::string& schema_name);

    /// \brief Set the table name in the KeyValueMetadata object.
    /// \param[in] table_name The table name.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& TableName(std::string& table_name);

    /// \brief Set the precision in the KeyValueMetadata object.
    /// \param[in] precision    The precision.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& Precision(int32_t precision);

    /// \brief Set the scale in the KeyValueMetadata object.
    /// \param[in] scale  The scale.
    /// \return           A ColumnMetadataBuilder.
    ColumnMetadataBuilder& Scale(int32_t scale);

    /// \brief Set the IsAutoIncrement in the KeyValueMetadata object.
    /// \param[in] is_auto_increment  The IsAutoIncrement.
    /// \return                     A ColumnMetadataBuilder.
    ColumnMetadataBuilder& IsAutoIncrement(bool is_auto_increment);

    /// \brief Set the IsCaseSensitive in the KeyValueMetadata object.
    /// \param[in] is_case_sensitive The IsCaseSensitive.
    /// \return                    A ColumnMetadataBuilder.
    ColumnMetadataBuilder& IsCaseSensitive(bool is_case_sensitive);

    /// \brief Set the IsReadOnly in the KeyValueMetadata object.
    /// \param[in] is_read_only   The IsReadOnly.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& IsReadOnly(bool is_read_only);

    /// \brief Set the IsSearchable in the KeyValueMetadata object.
    /// \param[in] is_searchable The IsSearchable.
    /// \return                 A ColumnMetadataBuilder.
    ColumnMetadataBuilder& IsSearchable(bool is_searchable);

    ColumnMetadata Build() const;

   private:
    std::shared_ptr<arrow::KeyValueMetadata> metadata_map_;

    /// \brief Default constructor.
    ColumnMetadataBuilder();
  };
};
}  // namespace sql
}  // namespace flight
}  // namespace arrow
