const obj1={
    name: "Object 1",
    // Both valid in ES6
    walk: function() {},
    talk() {}
};
person.talk();
// Both are also eq.
person['name']='Hello';
person.name='Hell';