#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "heap.h"
#include "stack.h"
#include "state.h"
#include "stream.h"
#include <stdint.h>

typedef STATE (*EXECUTOR)(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_loadarg(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_call(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_return(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_halt(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_print(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Pointer & memory operations
STATE op_ppush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_alloc(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_dealloc(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// String operations
STATE op_scat(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_sprint(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Integer operations
STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_isub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_idiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_imul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iand(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ior(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ixor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_inot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_irshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Unsigned integer operations
STATE op_uipush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uiadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uisub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uidiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uimul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uiand(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uior(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uixor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uinot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uirshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Long operations
STATE op_lpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ladd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_land(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lxor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lnot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_llshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Unsigned long operations
STATE op_ulpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uladd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uland(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulxor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulnot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ullshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Float operations
STATE op_fpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fdiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* EXECUTOR_H */