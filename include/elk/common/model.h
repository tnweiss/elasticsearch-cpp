//
// Created by tnwei on 1/9/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_MODEL_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_MODEL_H_

#include "magic_enum.hpp"
#include "string"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"
#include "elk/elasticsearch/models/index_types.h"
#include "exceptions.h"

namespace elk {
class Model {
 public:
  /**
   * Converts model to string
   * @return
   */
  [[nodiscard]] std::string to_string() const;

 protected:
  /**
   * Initialize with a json string
   * @param jsonString
   */
  explicit Model(const std::string &jsonString);

  /**
   * Initialize with a json object
   * @param json
   */
  explicit Model(const nlohmann::json &json);

  /**
   * Initialize with a reference to another json object
   * @param json
   */
  Model(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer  basePointer);

  /**
   * Copy constructor
   * @param model
   */
  Model(const Model& model);

  /**
   * Move constructor
   * @param model
   */
  Model(Model&& model) noexcept;

  /**
   * Get a string from the internal map
   * @param key
   * @return
   */
  std::string get_string(const char *key) const;

  /**
 * Get a string from the internal map
 * @param key
 * @param default
 * @return
 */
  std::string get_string(const char *key, const char *defaultVal) const;

  /**
   * Get an integer from the internal map
   * @param key
   * @return
   */
  int get_int(const char *key) const;

  /**
   *
   * @param key
   * @param defaultValue
   * @return
   */
  int get_int(const char* key, int defaultValue);

  /**
   * Get a long from the internal map
   * @param key
   * @return
   */
  long get_long(const char *key) const;

  /**
   *
   * @param key
   * @param defaultValue
   * @return
   */
  long get_long(const char* key, long defaultValue);

  /**
 * Get a long from the internal map
 * @param key
 * @return
 */
  bool get_bool(const char *key) const;

  /**
   *
   * @param key
   * @param defaultValue
   * @return
   */
  bool get_bool(const char* key, bool defaultValue);

  /**
   *
   * @param key
   * @param val
   */
  void set(const char* key, std::string val) const;

  /**
   *
   * @param key
   * @param val
   */
  void set(const char* key, const char* val) const;

  /**
   *
   * @param key
   * @param val
   */
  void set(const char* key, int val) const;

  /**
   *
   * @param key
   * @param val
   */
  void set(const char* key, long val) const;

  /**
   *
   * @param key
   * @param val
   */
  void set(const char* key, bool val) const;

  /**
   *
   * @param key
   * @param val
   */
  void set(const char *key, Model& val) const;

  /**
   * Get an object from the internal map
   * @param key
   * @return
   */
  template<typename T, typename std::enable_if<std::is_base_of<Model, T>::value>::type * = nullptr>
  T get_object(const char *key) const {
    nlohmann::json::json_pointer newPtr(_basePointer);
    newPtr.push_back(key);

    spdlog::debug(std::string("Model::_basePointer(") + _basePointer.to_string() + ")");
    spdlog::debug(std::string("get_object(") + key + ")");
    spdlog::debug(std::string("newPtr(") + newPtr.to_string() + ")");
    spdlog::debug("");

    T t(_json, newPtr);
    return t;
  }

  /**
 * Get an object from the internal map
 * @param key
 * @return
 */
  template<typename T, typename std::enable_if<std::is_base_of<Model, T>::value>::type * = nullptr>
  T get_object(const char *key, T defaultValue) const {
    if (_json->contains(key)) {
      return T((*_json)[key]);
    }

    return defaultValue;
  }

  /**
   * Get string value as an enum
   * @tparam T
   * @param key
   * @return
   */
  template<class T, typename std::enable_if<std::is_enum<T>::value>::type * = nullptr>
  T get_enum(const char* key) const {
    auto val = magic_enum::enum_cast<T>(get_string(key));

    if (val.has_value()) {
      return val.value();
    }

    spdlog::error(std::string("No value found for key (") + key + ") value(" + get_string(key, "") + ")");
    throw elk::ELKException("No enum value");
  }

  /**
   * Get string value as an enum
   * @tparam T
   * @param str_val
   * @return
   */
  template<class T, typename std::enable_if<std::is_enum<T>::value>::type * = nullptr>
  T get_enum(std::string str_val) const {
    auto val = magic_enum::enum_cast<T>(str_val);

    if (val.has_value()) {
      return val.value();
    }

    spdlog::error(std::string("No value found for value(" + str_val + ")"));
    throw elk::ELKException("No enum value");
  }

  /**
   *
   * @tparam T
   * @param key
   * @param value
   */
  template<class T, typename std::enable_if<std::is_enum<T>::value>::type * = nullptr>
  void set_enum(const char* key, T value) {
    set(key, std::string(magic_enum::enum_name(value)));
  }

  /**
   * output json of object
   * @return
   */
  friend std::ostream& operator<<(std::ostream& stream, const Model& model) {
    stream << (*model._json)[model._basePointer].dump(2) << std::endl;
  }

 private:
  const std::shared_ptr<nlohmann::json> _json;
  const nlohmann::json::json_pointer _basePointer;

  /**
   *
   * @param key
   * @return
   */
  nlohmann::json::json_pointer attr_pointer(const char* key) const;
};
}

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_MODEL_H_
