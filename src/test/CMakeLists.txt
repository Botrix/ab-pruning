include_directories(${ab_pruning_SOURCE_DIR}/lib/gtest/include)

add_executable(test_all test_all.cc test_ab_node.cc)

target_link_libraries(test_all gtest ABNode)

add_test(TestAll test_all)
