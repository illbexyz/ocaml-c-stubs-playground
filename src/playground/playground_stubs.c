#define CAML_NAME_SPACE

#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
// #include <caml/custom.h>
// #include <caml/callback.h>
#include <caml/fail.h>

#include "playground.h"
#include "animal.h"

#define check_ml_str_and_fail_if_contains_null(str)\
    if (!caml_string_is_c_safe(str)) {\
        char *err_msg_template = "Argument '%s' is followed by a null byte";\
        size_t mem_needed = snprintf(NULL, 0, err_msg_template, str);\
        char *err_msg = malloc(mem_needed);\
        sprintf(err_msg, err_msg_template, str);\
        caml_failwith(err_msg);\
    }

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

void hello_world_stub()
{
    CAMLparam0();
    hello_world();
    CAMLreturn0;
}

/**
* Not sure if there's a way to stub array functions in O(1) time instead of O(n) 
*/
CAMLprim value
sum_int_array_stub(value vArray) {
    CAMLparam1(vArray);
    int size = Wosize_val(vArray);
    int array[size];
    int res;

    for (int i = 0; i < size; i++) {
        array[i] = Int_val(Field(vArray, i));
    }

    res = sum_int_array(array, size);
    CAMLreturn(Val_int(res));
}

// Can't find a way to stub the original C function
void array_head_to_zero_stub(value vArray) {
    CAMLparam1(vArray);
    caml_modify(&Field(vArray, 0), Val_int(0));
    CAMLreturn0;
}

CAMLprim value
concat_strings_stub(value vStr1, value vStr2) {
    CAMLparam2(vStr1, vStr2);
    CAMLlocal1(vRes);
    check_ml_str_and_fail_if_contains_null(vStr1);
    check_ml_str_and_fail_if_contains_null(vStr2);
    char *s1 = String_val(vStr1);
    char *s2 = String_val(vStr2);
    char *res = concat_strings(s1, s2);
    vRes = caml_copy_string(res);
    CAMLreturn(vRes);
}

CAMLprim value
new_animal_stub() {
    CAMLparam0();
    Animal *animal = animal_new("Animalo");
    value v_pointer = caml_alloc(1, Abstract_tag);
    Field(v_pointer, 0) = (value) animal;
    // TODO: What happens when this value will get GC-ed?
    // it should call the animal destructor in some way
    CAMLreturn(v_pointer);
}

// TODO: new_dog, new_cat stubs

void animal_speak_stub(value v_animal) {
    CAMLparam1(v_animal);
    Animal *animal = (Animal*) Field(v_animal, 0);
    animal_speak(animal);
    CAMLreturn0;
}

// void create_animal_speak_stub()
// {
//     CAMLparam0();
//     Animal *animal = animal_new("Animalo");
//     Dog *dog = dog_new("Charlie");
//     Cat *cat = cat_new("Felix");
//     animal_speak(animal);
//     animal_speak((Animal*) dog);
//     animal_speak((Animal*) cat);
//     CAMLreturn0;
// }