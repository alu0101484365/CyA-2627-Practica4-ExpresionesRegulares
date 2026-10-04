#pragma once

#include <string>

class Attribute {
 public:
  Attribute(int line, const std::string& tag_name, const std::string& name, const
  std::string& value);
  int GetLine() const;
  std::string GetTagName() const;
  std::string GetName() const;
  std::string GetValue() const;
 private:
  int line_;
  std::string tag_name_;
  std::string name_;
  std::string value_;
};