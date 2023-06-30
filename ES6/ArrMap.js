const colors=['Red','Green','Blue'];
const new_colors=colors.map(color=>'<li>'+color+'<\li>');
// Can achieve same using template literal
const temp_colors=colors.map(color=>`<li>${color}<\li>`);
console.log(new_colors);
console.log(temp_colors);