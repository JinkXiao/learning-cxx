#include "../exercise.h"
#include <numeric>
#include <vector>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    using namespace std;

    int shape[]{1, 3, 224, 224};
    std::vector<int> shapeV(4, 0);
    memcpy(&shapeV[0], shape, sizeof(DataType) * 4);
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    // int size =
    int size = std::accumulate(shapeV.begin(), shapeV.end(), sizeof(DataType), std::multiplies<int>());
    std::cout << size << std::endl;
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
