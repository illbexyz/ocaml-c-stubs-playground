let sum_res = Playground.sum 1 2

let () =
  let arr = [|1; 2; 3|] in
  let () = Playground.array_head_to_zero arr in
  Array.iter print_int arr

;;
print_newline ()

(* let expected = "hello world" in *)
(* let actual = Playground.concat_strings "hello" " world" in
    let () = Gc.full_major () in
    print_string (actual ^ "\n") *)
(* Playground.sum_int_array [|1; 2|] 2 *)
(* let () = Playground.hello_world () in
    print_endline ("The result of 1 + 2 is: " ^ string_of_int sum_res) *)
