var colors = Array('white', 'red', 'blue', 'yellow');
var prev = [];

for(var j = 0; j < 30; j++){
    var row = document.createElement("div");
    row.className='row';
    
    var values = [];
    var prev_col;
    for(var i = 0; i < 60; i++) {

        var index = Math.floor(Math.random()*colors.length);
        if((prev.length == 0 || prev[i] != index) && prev_col != index){
        prev_col = index;
        var color = colors[index];
        var block = document.createElement("div");
        var blblock = document.createElement("div");

        block.style.backgroundColor = color;
        blblock.style.backgroundColor = 'black';
        
        row.appendChild(block);
        row.appendChild(blblock);
        values.push(index);
        }
        else {
            i--;
        }
    }
    prev = values;
    document.getElementById("container").appendChild(row);

}