#include <stdio.h>
#include <stdbool.h>

#include "animal.h"

static AnimalVTable _animal_vtable;
static bool _animal_vtable_initialized;

static void _animal_speak(Animal *self) {
    printf("Hi, i'm a generic animal, my name is %s\n", self->name);
}

static void _animal_vtable_init() {
    if (!_animal_vtable_initialized) {
        _animal_vtable.speak = &_animal_speak;
        _animal_vtable_initialized = true;
    }
}

const AnimalVTable* _animal_vtable_get(){
    _animal_vtable_init();
    return &_animal_vtable;
}

Animal animal_init(char *name) {
    _animal_vtable_init();
    Animal animal;
    animal.name = name;
    animal.vtable = &_animal_vtable;
    return animal;
}

// ============================= Dog =====================================

static AnimalVTable _dog_vtable;
static bool _dog_vtable_initialized;

void _dog_speak(Animal *self) {
    printf("Woof woof! I'm %s\n", self->name);
}

static void _dog_vtable_init() {
    if (!_dog_vtable_initialized) {
        _dog_vtable = *_animal_vtable_get();

        _dog_vtable.speak = &_dog_speak;
        _dog_vtable_initialized = true;
    }
}

Dog dog_init(char *name) {
    _dog_vtable_init();
    Animal parent = animal_init(name);
    Dog dog;
    dog.parent = parent;
    dog.parent.vtable = &_dog_vtable;
    return dog;
}

// ============================= Cat =====================================

static AnimalVTable _cat_vtable;
static bool _cat_vtable_initialized;

void _cat_speak(Animal *self) {
    printf("Meow! I'm %s\n", self->name);
}

static void _cat_vtable_init() {
    if (!_cat_vtable_initialized) {
        _cat_vtable = *_animal_vtable_get();

        _cat_vtable.speak = &_cat_speak;
        _cat_vtable_initialized = true;
    }
}

Cat cat_init(char *name) {
    _cat_vtable_init();
    Animal parent = animal_init(name);
    Cat cat;
    cat.parent = parent;
    cat.parent.vtable = &_cat_vtable;
    return cat;
}