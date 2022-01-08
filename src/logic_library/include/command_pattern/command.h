//
// Created by khalil on 1/7/22.
//

#ifndef DOODLEJUMP_COMMAND_H
#define DOODLEJUMP_COMMAND_H
namespace DoodleJump{
    class Command{
    public:
        Command() = default;

        virtual void execute() = 0;

    };
}
#endif //DOODLEJUMP_COMMAND_H
