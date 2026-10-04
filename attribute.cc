#include "attribute.h"

Attribute::Attribute(int line, const std::string& tag_name, const std::string& name, const std::string& value) : line_(line), tag_name_(tag_name), name_(name), value_(value) {}

int Attribute::GetLine() const {
 return line_;
}

std::string Attribute::GetTagName() const {
 return tag_name_;
}

std::string Attribute::GetName() const {
 return name_;
}

std::string Attribute::GetValue() const {
 return value_;
}
