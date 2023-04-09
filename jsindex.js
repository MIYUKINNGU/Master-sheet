const MAX = 10;

function print(text) {
    console.log(text);
}

function func(FUNC) {
    console.log(FUNC(0,0))
}

func((A,B)=>{return A+B+2});

class Vector2 {
    x = 0;
    y = 0;
}

class Vector3 extends Vector2
{
    z = 0
    Reset() {
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }
}

console.log("Hello, World!");
print("New function");

let intvar = 0;

intver = intver + 10;

let Variable = new Vector3();

print(Variable);

Variable.Reset();

print(Variable);

console.log(typeof(Variable));

if (1) {
    for (let i = 0;i<MAX;i--) {
        i++;
        i++;
    }
}
