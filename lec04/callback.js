fetch("https://jsonplaceholder.typicode.com/todos/1").then(res => res.text()).then(console.log);

console.log("We can do other stuff while the data is fetched in the background");
