const products = {
    0: {
        "image": "../images/1.jpeg",
        "title": "Jaranga dress",
        "price": "10400.00",
        "desc" : "Loose dress-shirt straight silhouette with a drawstring at the waist. Button clasp. Sleeves of a shirt cut with the lowered line of a shoulder. The dress is made of ecoleather on suede, pleasant to a body. You can wear a dress-shirt buttoned or crocheted as a light cloak.",
        "size":[ "S-M","M-L"],
        "color": ["rgb(206, 200, 190)","rgb(163, 145, 129)"],
        "composition": "polyethylene - 100%, polyurethane - 100%",
        "care": ["Do not leave under the sunlight or near the heater",
                "Do not bleach",
                "Dry cleaning",
                "No machine drying",
                "Inside out wash only"],
        "table":[
                ["SIZE","BUST", "WAIST", "LENGTH"],
                ["SM","104", "104", "119"],
                ["M-L","112", "112", "120"]
            ]
    },
    1: {
        "image": "../images/2.jpg",
        "title": "Seamless handmade wool sweater",
        "price": "6500.00",
        "desc" : "Seamless straight silhouette sweater with high collar. It has three-dimensional sleeves narrowed to the cuffs. The cuffs and the lower edge are knitted with a wide elastic band. We recommend combining a sweater with skirts and pants, jeans and dresses made of light materials.",
        "size":[ "XS","S", "M"],
        "color": ["rgb(173,161,142)", "rgb(222,209,187)", "rgb(164,211,241)", "rgb(136,40,83)", "rgb(77,77,77)"],
        "composition": "wool - 65%, alpaca - 35%",
        "care": ["Wash by hand at water temperature up to 30°C",
                "Iron at temperatures up to 150°C on the reverse side",
                "Do not bleach",
                "Dry cleaning",
                "No machine drying",
                "Dry vertically and straightened"],
        "table":[
                ["SIZE","BUST", "WAIST", "LENGTH"],
                ["XS","96", "96", "52"],
                ["S","102", "102", "55"],
                ["s-M","108", "108", "58"]
            ]
    },
    2: {
        "image": "../images/4.jpg",
        "title": "Suit with a top and pants",
        "price": "3300.00",
        "desc" : "Tencel suit, which consists of pants with a rubber band and a top. Straight pants with pockets in the side seams. Top straight silhouette with deep cuts in the side seams. Fastens with buttons on the back. This suit will be on occasion on vacation for hiking or flying.",
        "size":["S-M", "M-L"],
        "color": ["rgb(208, 184, 146)"],
        "composition": "tencel - 77%, triacetate - 23%",
        "care": ["Wash by hand at water temperature up to 30°C",
                "Iron at temperatures up to 150°C on the reverse side",
                "Do not bleach",
                "Dry cleaning",
                "No machine drying",
                "Dry vertically and straightened"],
        "table": [
                ["SIZE","BUST", "WAIST", "LENGTH"],
                ["S-M", "94", "94", "69"],
                ["M-L", "102", "102", "70"],
                ["L", "108", "108", "73"]
            ]
    }
};
var temp;
const queryString = window.location.search;
const urlParams = new URLSearchParams(queryString);
const product_number = urlParams.get('product');

const product = products[product_number];

// image
document.querySelector('.product-main-image img').setAttribute('src', product['image']);

// title
document.querySelector('.product-main-title').textContent = product['title'];
// price
document.querySelector('.product-main-price').textContent = product['price'] + " UAH";
// price
document.querySelector('.product-main-desc').textContent = product['desc'];
// size
var size =  document.querySelector('.product-main-sizes');
var temp_size = document.getElementById('tsize-plates').content.cloneNode(true);

var i = 0;
product['size'].forEach(value => {

    temp = temp_size.cloneNode(true);
    var input = temp.querySelector('input');
    input.setAttribute('id', 'size'+i);

    var label = temp.querySelector('label');
    label.setAttribute('for', 'size'+i);
    label.textContent = value;

    size.append(input);
    size.append(label);
    i++;
})

// color
var color =  document.querySelector('.product-main-colors');
var temp_color = document.getElementById('tcolor-plates').content.cloneNode(true);

var i = 0;
product['color'].forEach(value => {

    temp = temp_color.cloneNode(true);
    var input = temp.querySelector('input');
    input.setAttribute('id', 'color'+i);

    var label = temp.querySelector('label');
    label.setAttribute('for', 'color'+i);
    label.querySelector('.color').style['background'] = value;

    color.append(input);
    color.append(label);
    i++;
})

// table
const table = product["table"];

var temp_table = document.getElementById("tsize-table-plate").content.cloneNode(true).querySelector('.size-table-plate');
var table_html = document.querySelector('.size-table');

table.forEach(line => {
    line.forEach(plate => {
        temp = temp_table.cloneNode(true);
        temp.textContent = plate;
        table_html.append(temp);
    })
});

// composition
document.querySelector('.product-main-composition').textContent = product['composition'];

// care
var care = document.querySelector('.product-main-care');

product['care'].forEach(value => {
    care.textContent += value;
    care.textContent += '\n';
})