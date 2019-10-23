<?php

//read file lines to an array
$file_lines_to_array = file('data.txt');

//get the first and last line
$first_line = $file_lines_to_array[0];
$last_line = end($file_lines_to_array);

//create the file if it doesn't exist
$new_txt_file = fopen("write_php.txt", "w") or die("Unable to open file!");
//put the content with a line between
$content = $first_line."\n".$last_line;
//write the file
fwrite($new_txt_file, $content);
//close the file
fclose($new_txt_file);

?>