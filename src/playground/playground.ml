module Types = struct
  (* obj represents an object built from C.
    It is contravariant, meaning that if 'a is subtype of 'b,
    then 'a obj is supertype of 'b obj *)
  
  type -'a obj

  type animal = [`base]
  type dog = [animal | `dog]
  type cat = [animal | `cat]

  (* In this example "animal" is a subtype of "dog", hence by the
   contravariance rule "animal obj" is a supertype of "dog obj" *)
end

open Types

module Animal = struct
  external new_animal : string -> animal obj = "new_animal_stub"
  external animal_speak : animal obj -> unit = "animal_speak_stub"
end

module Dog = struct
  external new_dog : string -> dog obj = "new_dog_stub"
end

class animal obj = object
  method animal_speak () = Animal.animal_speak obj
end

let animal ~name = new animal (Animal.new_animal name)

class dog obj = object
  inherit animal (obj :> Types.animal obj)
  method do_you_wanna_walk () = "Yes pleease!"
end

let dog ~name = new dog (Dog.new_dog name)

external hello_world : unit -> unit = "hello_world_stub"

external sum : int -> int -> int = "sum_stub"

external sum_int_array : int array -> int = "sum_int_array_stub"

external array_head_to_zero : int array -> unit = "array_head_to_zero_stub"

external concat_strings : string -> string -> string = "concat_strings_stub"

let%test "sum" = sum 1 2 = 3

let%test "sum_int_array" =
  let arr = [|1; 2; 3; 4; 5|] in
  sum_int_array arr = Array.fold_left ( + ) 0 arr

let%test "array head to zero" =
  let arr = [|9; 8; 7; 6|] in
  let () = array_head_to_zero arr in
  arr = [|0; 8; 7; 6|]

let%test "concat_strings" =
  let expected = "hello world" in
  let actual = concat_strings "hello" " world" in
  actual = expected

let%test "concat_string with null bytes" =
  let result =
    try concat_strings "hel\x00lo" " world" with
    | Failure _s ->
        "error"
    | _ ->
        assert false
  in
  result = "error"
