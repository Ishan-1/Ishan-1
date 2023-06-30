const address={
    street: 'S',
    city: 'C',
    country: 'Co'
};

//Traditional way to do this
const s1=address.street;
const ci1=address.city;
const co1=address.country;
console.log(s1);
// Easier way using destructuring
const {street:s2,ci2,co2} = address;
console.log(s2);