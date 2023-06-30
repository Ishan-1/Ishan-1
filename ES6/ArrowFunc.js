const square =function(num)
{
    return num*num;
};

const sq= number => number*number;

console.log(square(5));
console.log(sq(5));

// Demonstration using filter() => Requires a function that will be passed all elements of array

const ch= ['a','b','c','d','a'];
// Easy to filter using arrow function
const onlya=ch.filter(c=>c=='a');
console.log(onlya);
// Arrow functions don't rebind 'this'

