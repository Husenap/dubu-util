#include <dubu_util/dubu_util.h>
#include <gtest/gtest.h>

TEST(dubu_util, type_id) {
	struct CustomType {};

	CustomType c;
	int        i;

	EXPECT_EQ(dubu::util::TypeId::Get<int>(), 1u);
	EXPECT_EQ(dubu::util::TypeId::Get<float>(), 2u);
	EXPECT_EQ(dubu::util::TypeId::Get<double>(), 3u);
	EXPECT_EQ(dubu::util::TypeId::Get<CustomType>(), 4u);
	EXPECT_EQ(dubu::util::TypeId::Get<int>(), 1u);
	EXPECT_EQ(dubu::util::TypeId::Get<CustomType>(), 4u);
	EXPECT_EQ(dubu::util::TypeId::Get(c), 4u);
	EXPECT_EQ(dubu::util::TypeId::Get(i), 1u);
	EXPECT_EQ(dubu::util::TypeId::Get(c),
	          dubu::util::TypeId::Get<CustomType>());
	EXPECT_EQ(dubu::util::TypeId::Get(i), dubu::util::TypeId::Get<int>());
}
