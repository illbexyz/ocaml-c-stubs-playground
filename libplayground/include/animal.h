#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct _Animal Animal;
typedef struct _AnimalVTable AnimalVTable;

struct _Animal {
    char *name;
    AnimalVTable *vtable;
};

struct _AnimalVTable {
    void (*destructor)(Animal *self);
    void (*speak)(Animal *self);
};

Animal* animal_new(char *name);
void animal_delete(Animal *animal);

static inline void animal_speak(Animal *animal) {
    animal->vtable->speak(animal);
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
    void (*destructor)(Animal *self);
    void (*speak)(Animal *self);
};

Dog* dog_new(char *name);
void dog_delete(Dog *dog);

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
    void (*destructor)(Animal *self);
    void (*speak)(Animal *self);
};

Cat* cat_new(char *name);
void cat_delete(Cat *cat);

static inline Animal* cat_to_animal(Cat *self) {
    return &(self->parent);
}

#endif