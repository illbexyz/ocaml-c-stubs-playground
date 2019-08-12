let () =
  let open Playground in
  print_endline "Testing animal class:";
  let animal = animal ~name:"Rufus" in
  animal#animal_speak ();
  print_newline ()

let () =
  let open Playground in
  print_endline "Testing dog class:";
  let dog = dog ~name:"Charlie" in
  dog#animal_speak ();
  print_endline @@ dog#do_you_wanna_walk ();
  print_newline ()

let () =
  print_endline "Testing hello_world:";
  Playground.hello_world ();
  print_newline ()

let () =
  print_endline "Testing array_head_to_zero ([|1; 2; 3|]):";
  let arr = [|1; 2; 3|] in
  Playground.array_head_to_zero arr;
  Array.iter print_int arr;
  print_string "\n\n"

let () = 
  print_endline "Testing concat_strings ('hello', ' world'):";
  let res = Playground.concat_strings "hello" " world" in
  Gc.full_major ();
  print_string (res ^ "\n");
  print_newline ()

let () =  
  print_endline "Testing sum_int_array [|1; 2|]:";
  let res = Playground.sum_int_array [|1; 2|] in
  print_endline ("Result: " ^ string_of_int res)