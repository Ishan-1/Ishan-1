export class Person 
{
    constructor(name)
    {
        this.name=name;
    }
    walk()
    {
        console.log(this.name," is walking");
    }
};

//Inherting using extends keyword
export class Teacher extends Person
{
    teach()
    {
        console.log(this.name,"is teaching");
    }
};
// If child constructor is defined, then it must call parent constructor using super(<Args of parent constructor>)

