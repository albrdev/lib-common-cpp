#include <gtest/gtest.h>
#include "String.hpp"

using namespace ::testing;

namespace UnitTest
{
  TEST(String, IsWhitespace)
  {
    ASSERT_TRUE(String::IsWhitespace(""));
    ASSERT_TRUE(String::IsWhitespace(" "));
    ASSERT_TRUE(String::IsWhitespace("\t"));
    ASSERT_TRUE(String::IsWhitespace("\v"));
    ASSERT_TRUE(String::IsWhitespace("\n"));
    ASSERT_TRUE(String::IsWhitespace("\r"));
    ASSERT_TRUE(String::IsWhitespace("\f"));
    ASSERT_TRUE(String::IsWhitespace(" \t\v\n\r\f"));

    ASSERT_FALSE(String::IsWhitespace("abc"));
    ASSERT_FALSE(String::IsWhitespace("abc \t\v\n\r\f"));
    ASSERT_FALSE(String::IsWhitespace(" \t\v\n\r\fabc"));
    ASSERT_FALSE(String::IsWhitespace(" \t\vabc\n123\r\f"));
  }

  TEST(String, CompareIgnoreCase)
  {
    ASSERT_TRUE(String::CompareIgnoreCase("", ""));
    ASSERT_TRUE(String::CompareIgnoreCase("abc", "abc"));
    ASSERT_TRUE(String::CompareIgnoreCase("ABC", "ABC"));
    ASSERT_TRUE(String::CompareIgnoreCase("Abc 123", "aBC 123"));

    ASSERT_FALSE(String::CompareIgnoreCase("", " "));
    ASSERT_FALSE(String::CompareIgnoreCase(" ", ""));
    ASSERT_FALSE(String::CompareIgnoreCase("", "abc"));
    ASSERT_FALSE(String::CompareIgnoreCase("abc", ""));
    ASSERT_FALSE(String::CompareIgnoreCase("abc", "abc 123"));
    ASSERT_FALSE(String::CompareIgnoreCase("abc 123", "abc"));
    ASSERT_FALSE(String::CompareIgnoreCase("ABC", "ABC 123"));
    ASSERT_FALSE(String::CompareIgnoreCase("ABC 123", "ABC"));
    ASSERT_FALSE(String::CompareIgnoreCase("Abc", "aBC 123"));
    ASSERT_FALSE(String::CompareIgnoreCase("Abc 123", "aBC"));
  }

  TEST(String, Trim)
  {
    ASSERT_EQ(String::Trim(""), "");
    ASSERT_EQ(String::Trim("abc"), "abc");
    ASSERT_EQ(String::Trim(" abc"), "abc");
    ASSERT_EQ(String::Trim("abc "), "abc");
    ASSERT_EQ(String::Trim(" abc "), "abc");
    ASSERT_EQ(String::Trim("abc 123"), "abc 123");
    ASSERT_EQ(String::Trim(" abc 123"), "abc 123");
    ASSERT_EQ(String::Trim("abc 123 "), "abc 123");
    ASSERT_EQ(String::Trim(" abc 123 "), "abc 123");
    ASSERT_EQ(String::Trim(" \t\v\n\r\fabc \t\v\n\r\f123 \t\v\n\r\f"), "abc \t\v\n\r\f123");
  }

  TEST(String, TrimLeft)
  {
    ASSERT_EQ(String::TrimLeft(""), "");
    ASSERT_EQ(String::TrimLeft("abc"), "abc");
    ASSERT_EQ(String::TrimLeft(" abc"), "abc");
    ASSERT_EQ(String::TrimLeft("abc "), "abc ");
    ASSERT_EQ(String::TrimLeft(" abc "), "abc ");
    ASSERT_EQ(String::TrimLeft("abc 123"), "abc 123");
    ASSERT_EQ(String::TrimLeft(" abc 123"), "abc 123");
    ASSERT_EQ(String::TrimLeft("abc 123 "), "abc 123 ");
    ASSERT_EQ(String::TrimLeft(" abc 123 "), "abc 123 ");
    ASSERT_EQ(String::TrimLeft(" \t\v\n\r\fabc \t\v\n\r\f123 \t\v\n\r\f"), "abc \t\v\n\r\f123 \t\v\n\r\f");
  }

  TEST(String, TrimRight)
  {
    ASSERT_EQ(String::TrimRight(""), "");
    ASSERT_EQ(String::TrimRight("abc"), "abc");
    ASSERT_EQ(String::TrimRight(" abc"), " abc");
    ASSERT_EQ(String::TrimRight("abc "), "abc");
    ASSERT_EQ(String::TrimRight(" abc "), " abc");
    ASSERT_EQ(String::TrimRight("abc 123"), "abc 123");
    ASSERT_EQ(String::TrimRight(" abc 123"), " abc 123");
    ASSERT_EQ(String::TrimRight("abc 123 "), "abc 123");
    ASSERT_EQ(String::TrimRight(" abc 123 "), " abc 123");
    ASSERT_EQ(String::TrimRight(" \t\v\n\r\fabc \t\v\n\r\f123 \t\v\n\r\f"), " \t\v\n\r\fabc \t\v\n\r\f123");
  }

  TEST(String, Reverse)
  {
    {
      std::string value = "Abc 123";
      String::Reverse(value);
      ASSERT_EQ(value, "321 cbA");
    }

    {
      std::string value = "Abc123";
      String::Reverse(value);
      ASSERT_EQ(value, "321cbA");
    }

    {
      std::string value = "Abc 123";
      ASSERT_EQ(String::Reverse(value), "321 cbA");
    }

    {
      std::string value = "Abc123";
      ASSERT_EQ(String::Reverse(value), "321cbA");
    }
  }

  TEST(String, ReverseCopy)
  {
    {
      std::string value = "Abc 123";
      ASSERT_EQ(String::ReverseCopy(value), "321 cbA");
    }

    {
      std::string value = "Abc123";
      ASSERT_EQ(String::ReverseCopy(value), "321cbA");
    }
  }
} // namespace UnitTest
