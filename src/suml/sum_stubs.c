// #define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/memory.h>
// #include <caml/alloc.h>
// #include <caml/custom.h>
// #include <caml/callback.h>
// #include <caml/fail.h>

#include "sum.h"

CAMLprim value
sum_stub(value x, value y)
{
    CAMLparam2(x, y);
    int i, j, res;
    i = Int_val(x);
    j = Int_val(y);
    res = sum(i, j);
    CAMLreturn (Val_int(res));
}