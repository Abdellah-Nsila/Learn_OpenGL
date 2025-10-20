#include "core/Engine.hpp"
#include <vector>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()

std::vector<glm::vec3> generateRandomPositions(int N, float minRange = -50.0f, float maxRange = 50.0f)
{
    std::vector<glm::vec3> positions;
    positions.reserve(N);

    // Seed random generator (only once in your program)
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    for (int i = 0; i < N; i++)
    {
        float x = minRange + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxRange - minRange)));
        float y = minRange + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxRange - minRange)));
        float z = minRange + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxRange - minRange)));

        positions.emplace_back(x, y, z);
    }

    return positions;
}

int N = 10;
auto randomCubePositions = generateRandomPositions(N, -10.0f, 10.0f);

