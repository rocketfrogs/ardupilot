#include "Rover.h"
// #include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void ModeNodeRed::_exit()
{
    // clear lateral when exiting manual mode
    g2.motors.set_throttle(0);
}

void ModeNodeRed::update()
{
    const char *filepath = "/run/shm/node_red_cmd.txt";
    int fd = open(filepath, O_RDONLY | O_NONBLOCK);
    if (fd < 0)
    {
        return;
    }
    char buffer[128];
    auto size = read(fd, buffer, 127);
    close(fd);
    buffer[size] = 0;
    float t = -1.0f, s = -1.0f;
    if (sscanf(buffer, "T%f S%f", &t, &s) == 2)
    {
        // get or set throttle as a value from -100 to 100
        g2.motors.set_throttle(t);
        // get or set steering as a value from -4500 to +4500
        g2.motors.set_steering(s, false);
    }

    // std::ifstream infile(filepath);
    // if (infile.good())
    // {
    //     std::string line;
    //     std::getline(infile, line);
    //     float t = -1.0f, s = -1.0f;
    //     if (sscanf(line.c_str(), "T%f S%f", &t, &s) == 2)
    //     {
    //         // printf("setting steering to %f\n", s);
    //         g2.motors.set_throttle(t);
    //         g2.motors.set_steering(s);
    //     }
    // }
}
