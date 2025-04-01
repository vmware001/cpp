#include <random>
#include <iostream>

double generateRandom()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
}

void flyOnce(int &pos_x, int &pos_y, int &pos_z)
{
    double randomFloat = generateRandom();
    if (randomFloat < 1.0 / 6)
        pos_x += 1;
    else if (randomFloat < 1.0 / 3)
        pos_x -= 1;
    else if (randomFloat < 1.0 / 2)
        pos_y += 1;
    else if (randomFloat < 2.0 / 3)
        pos_y -= 1;
    else if (randomFloat < 5.0 / 6)
        pos_z += 1;
    else
        pos_z -= 1;
}

int simulation(int originPos_x, int originPos_y, int originPos_z, int maxStep)
{
    int pos_x = originPos_x;
    int pos_y = originPos_y;
    int pos_z = originPos_z;
    int step = 0;
    while (step < maxStep)
    {
        flyOnce(pos_x, pos_y, pos_z);
        step += 1;
        if (pos_x == originPos_x && pos_y == originPos_y && pos_z == originPos_z)
            return 1;
    }
    return 0;
}

int main()
{
    int sum = 0;
    int maxSimulationCount = 10000;
    int maxStep = 10000;
    int count = 0;
    while (count < maxSimulationCount)
    {
        sum += simulation(0, 0, 0, maxStep);
        count += 1;
    }
    double result = static_cast<double>(sum) / count;
    std::cout << result << std::endl;
}
