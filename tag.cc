#include "tag.h"

Tag::Tag(int line, const std::string& name) : line_(line), name_(name) {}

int Tag::GetLine() const {
 return line_;
}

std::string Tag::GetName() const {
 return name_;
}