const obj1={
    name: "Object 1",
    // Both valid in ES6
    walk: function() {console.log(this);}
};
obj1.walk();
// Global object returned
const w=obj1.walk;
w();
// Bind the obj1 to the method for standalone calls
const w2=obj1.walk.bind(obj1);
w2();