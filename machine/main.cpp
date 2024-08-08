#include <Windows.h>
#include <winable.h>

#include <iostream>
#include <chrono>
#include "colormod.h"

typedef std::chrono::high_resolution_clock Clock;

void ascii(Color::Modifier blue, Color::Modifier green, Color::Modifier cyan, Color::Modifier magenta)
{

    std::cout << cyan << "\n\n.sSSSSs.     .sSSS       s.         SSSSS       .sSSSSs.    .sSSSSs.    .sSSS  SSSSS" <<std::endl;
    std::cout << cyan <<"SSSSSSSSSs.  SSSSS       SSSs.      SSSSS       SSSSSSSSSs. SSSSSSSSSs. SSSSS  SSSSS" << std::endl;
    std::cout << blue << "S SSS SSSSS  S SSS       SSSSS      S SSS       S SSS SSSSS S SSS SSSSS S SSS SSSSS" << std::endl;
    std::cout << magenta << "S  SS SSSSS  S  SS       SSSSS      S  SS       S  SS SSSSS S  SS SSSS' S  SS SSSSS" << std::endl;
    std::cout << magenta << "S..SS SSSSS  S..SS       SSSSS      S..SS       S..SS SSSSS S..SS       S..SSsSSSSS" << std::endl;
    std::cout << magenta << "S:::S SSSSS  S:::S       SSSSS      S:::S       S:::S SSSSS S:::S SSSSS S:::S SSSSS" << std::endl;
    std::cout << blue << "S;;;S SSSSS  S;;;S   S   SSSSS      S;;;S       S;;;S SSSSS S;;;S SSSSS S;;;S  SSSSS" << std::endl;
    std::cout << cyan << "S&&&S SSSSS  S&&&S  SSS  SSSSS      S&&&S SSSSS S&&&S SSSSS S&&&S SSSSS S&&&S  SSSSS" << std::endl;
    std::cout << cyan << "SSSSSsSSSSss SSSSSsSS SSsSSSSS      SSSSSsSS;:' SSSSSsSSSSS SSSSSsSSSSS SSSSS   SSSSS\n\n" << std::endl;
}

int main()
{
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier cyan(Color::FG_CYAN);
    Color::Modifier magenta(Color::FG_MAGENTA);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    ascii(blue,green,cyan,magenta);

    long long duration;
    std::cout << green << "How long will you be away?" << green;
    std::cin >> duration;    

    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << magenta;
    BlockInput(true);
    while ((long long) duration *1000 > std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()) {
        t2 = Clock::now();
        std::cout << "\r\t" << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count(); 
        SetCursorPos(600, 600);
    }
    BlockInput(false);

    std::cout << cyan << "\nLocked Windows HID Input for>\n\n" << blue << ":: [(Delta t2-t1): " << green 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << cyan << " nanoseconds]\n\n" << def << std::endl;

    return 0;
}