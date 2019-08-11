#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "animal.h"

#define UNUSED(x) (void)(x)

static AnimalVTable _animal_vtable;
static bool _animal_vtable_initialized;

static void _animal_speak(Animal *self) {
    printf("Hi, i'm a generic animal, my name is %s\n", self->name);
}

static void _animal_destructor(Animal *self) {
    UNUSED(self);
    // nothing to free
}

void animal_delete(Animal *animal) {
    _animal_destructor(animal);
    free(animal);
}

static void _animal_vtable_init() {
    if (!_animal_vtable_initialized) {
        _animal_vtable.speak = _animal_speak;
        _animal_vtable.destructor = _animal_destructor;
        _animal_vtable_initialized = true;
    }
}

void _animal_constructor(Animal *self, char *name) {
    memset(self, 0x00, sizeof(Animal));

    _animal_vtable_init();
    self->vtable = &_animal_vtable;

    self->name = name;
}

Animal* animal_new(char *name) {
    Animal *self = (Animal*) malloc(sizeof(Animal));
    _animal_constructor(self, name);
    return self;
}

const AnimalVTable* _animal_vtable_get(){
    _animal_vtable_init();
    return &_animal_vtable;
}

// ============================= Dog =====================================

static AnimalVTable _dog_vtable;
static bool _dog_vtable_initialized;

void _dog_speak(Animal *self) {
    printf("Woof woof! I'm %s\n", self->name);
}

static void _dog_destructor(Dog *self) {
    self->parent.vtable->destructor(&self->parent);
}

static void _dog_vtable_init() {
    if (!_dog_vtable_initialized) {
        _dog_vtable = *_animal_vtable_get();

        _dog_vtable.speak = _dog_speak;
        _dog_vtable_initialized = true;
    }
}

void _dog_constructor(Dog *self, char *name) {
    memset(self, 0x00, sizeof(Dog));
    _animal_constructor(&self->parent, name);

    _dog_vtable_init();
    self->parent.vtable = &_dog_vtable;
}

void dog_delete(Dog *dog) {
    _dog_destructor(dog);
    free(dog);
}

Dog* dog_new(char *name) {
    Dog *self = (Dog*) malloc(sizeof(Dog));
    _dog_constructor(self, name);
    return self;
}

// ============================= Cat =====================================

static AnimalVTable _cat_vtable;
static bool _cat_vtable_initialized;

void _cat_speak(Animal *self) {
    printf("Meow! I'm %s\n", self->name);
}

static void _cat_destructor(Cat *self) {
    self->parent.vtable->destructor(&self->parent);
}

static void _cat_vtable_init() {
    if (!_cat_vtable_initialized) {
        _cat_vtable = *_animal_vtable_get();

        _cat_vtable.speak = _cat_speak;
        _cat_vtable_initialized = true;
    }
}

void _cat_constructor(Cat *self, char *name) {
    memset(self, 0x00, sizeof(Cat));
    _animal_constructor(&self->parent, name);

    _cat_vtable_init();
    self->parent.vtable = &_cat_vtable;
}

void cat_delete(Cat *cat) {
    _cat_destructor(cat);
    free(cat);
}

Cat* cat_new(char *name) {
    Cat *self = (Cat*) malloc(sizeof(Cat));
    _cat_constructor(self, name);
    return self;
}
