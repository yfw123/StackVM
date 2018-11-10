#include "opcode.h"
#include "stream.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    // char d[] = {
    //     OP_PUSH, 5, 0, // PUSH
    //     OP_CALL, 10, 0, 1, 0,
    //     OP_PRINT,
    //     OP_HALT,
    //     OP_LOADARG, 0, 0,
    //     OP_PUSH, 2, 0,
    //     OP_ADD,
    //     OP_RETURN,

    // };

    char d[] = {
        OP_I_PUSH, 5, 0, // PUSH
        OP_CALL, 14, 0, 1, 0,
        OP_I_PUSH, 27, 0,
        OP_I_OR,
        OP_PRINT,
        OP_HALT,
        OP_LOADARG, 0, 0,
        OP_I_PUSH, 2, 0,
        OP_ADD,
        OP_I_PUSH, 4, 0,
        OP_CALL, 30, 0, 2, 0,
        OP_RETURN,
        OP_LOADARG, 0, 0,
        OP_LOADARG, 1, 0,
        OP_ADD,
        OP_RETURN
    };

    STREAM program = stream_create(&d);

    VM vm = vm_create(&program);

    vm_run(&vm);

    vm_free(vm);

    return 0;
}
