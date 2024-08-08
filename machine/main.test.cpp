#include <Windows.h>
#include <winable.h>

#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

int main()
{
    long long duration;
    std::cout << "How long will you be away?";
    std::cin >> duration;

    auto t1 = Clock::now();
    auto t2 = Clock::now();

    BlockInput(true);
    while ((long long)duration * 1000 > std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count())
    {
        t2 = Clock::now();
        std::cout << "\r\t" << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        SetCursorPos(600, 600);
    }
    BlockInput(false);

    std::cout << "Delta t2-t1: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " nanoseconds" << std::endl;

    return 0;
}