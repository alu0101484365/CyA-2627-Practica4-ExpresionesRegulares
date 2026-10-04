#include "comment.h"

Comment::Comment(int start_line, int end_line, const std::string& text, bool is_description) : start_line_(start_line), end_line_(end_line), text_(text), is_description_(is_description) {}

int Comment::GetStartLine() const {
 return start_line_;
}

int Comment::GetEndLine() const {
 return end_line_;
}

std::string Comment::GetText() const {
 return text_;
}

bool Comment::IsDescription() const {
 return is_description_;
}
