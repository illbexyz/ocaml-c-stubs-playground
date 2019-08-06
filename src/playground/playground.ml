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
