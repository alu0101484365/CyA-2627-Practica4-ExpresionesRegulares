#pragma once

#include <string>

class Comment {
 public:
  Comment(int start_line, int end_line, const std::string& text, bool is_description = false);
  int GetStartLine() const;
  int GetEndLine() const;
  std::string GetText() const;
  bool IsDescription() const;
 private:
  int start_line_;
  int end_line_;
  std::string text_;
  bool is_description_;
};
