#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct _Animal Animal;
typedef struct _AnimalVTable AnimalVTable;

struct _Animal {
    char *name;
    AnimalVTable *vtable;
};

struct _AnimalVTable {
    void (*speak)(Animal *self);
};

Animal animal_init(char *name);

static inline void animal_speak(Animal *self) {
    self->vtable->speak(self);
}

// ============================= Dog =====================================

typedef struct _Dog Dog;
typedef struct _DogVTable DogVTable;

struct _Dog {
    Animal parent;
    const DogVTable *vtable;
};

struct _DogVTable {
    AnimalVTable *parent;
    void (*speak)(Animal *self);
};

Dog dog_init(char *name);

static inline Animal* dog_to_animal(Dog *self) {
    return &(self->parent);
}

// ============================= Cat =====================================

typedef struct _Cat Cat;
typedef struct _CatVTable CatVTable;

struct _Cat {
    Animal parent;
    const CatVTable *vtable;
};

struct _CatVTable {
    AnimalVTable *parent;
    void (*speak)(Animal *self);
};

Cat cat_init(char *name);

static inline Animal* cat_to_animal(Cat *self) {
    return &(self->parent);
}

#endif