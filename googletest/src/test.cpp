#include "../include/gtest/gtest.h"
#include "../../src/wordlearn.h"
#include <stdio.h>
#define n 30


TEST(VocabularyTests, EnRuTest)
{
	struct d w[n];
	Wl(w);
	int S[n];
	Voc(w, S);
	EXPECT_EQ(13, S[0]);
	EXPECT_EQ(1, S[1]);
	EXPECT_EQ(19, S[2]);
	EXPECT_EQ(23, S[10]);
	EXPECT_EQ(16, S[11]);
	EXPECT_EQ(6, S[20]);
	EXPECT_EQ(29, S[21]);
	EXPECT_EQ(11, S[27]);
	EXPECT_EQ(24, S[28]);
	EXPECT_EQ(15, S[29]);
}


TEST(VocabularyTests, RuEnTest)
{
	struct d w[n];
	int B[n];
	Wl(w);
	Voc1(w, B);
	EXPECT_EQ(24, B[0]);
	EXPECT_EQ(27, B[1]);
	EXPECT_EQ(17, B[2]);
	EXPECT_EQ(5, B[10]);
	EXPECT_EQ(16, B[11]);
	EXPECT_EQ(23, B[20]);
	EXPECT_EQ(7, B[21]);
	EXPECT_EQ(0, B[27]);
	EXPECT_EQ(18, B[28]);
	EXPECT_EQ(28, B[29]);
}


TEST(FillingTest, StructFill)
{
	struct d w[n];
	Wl(w);
	EXPECT_STREQ("duck", w[0].en);
	EXPECT_STREQ("утка", w[0].ru);
	EXPECT_STREQ("car", w[1].en);
	EXPECT_STREQ("машина", w[1].ru);
	EXPECT_STREQ("elevator", w[2].en);
	EXPECT_STREQ("лифт", w[2].ru);
	EXPECT_STREQ("frog", w[3].en);
	EXPECT_STREQ("лягушка", w[3].ru);
	EXPECT_STREQ("magic", w[14].en);
	EXPECT_STREQ("магия", w[14].ru);
	EXPECT_STREQ("world", w[15].en);
	EXPECT_STREQ("мир", w[15].ru);
	EXPECT_STREQ("time", w[27].en);
	EXPECT_STREQ("время", w[27].ru);
	EXPECT_STREQ("school", w[28].en);
	EXPECT_STREQ("школа", w[28].ru);
	EXPECT_STREQ("river", w[29].en);
	EXPECT_STREQ("река", w[29].ru);

}


































