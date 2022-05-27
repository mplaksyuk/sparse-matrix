var products = {
    0: {
        "image": "../images/1.jpeg",
        "title": "Jaranga dress",
        "price": "10400.00",
        "link" : "product.html?product=0"
    },
    1: {
        "image": "../images/2.jpg",
        "title": "Pullover",
        "price": "6500.00",
        "link" : "product.html?product=1"
    },
    2: {
        "image": "../images/4.jpg",
        "title": "Suit with a top and pants",
        "price": "3300.00",
        "link" : "product.html?product=2"
    }
};

var cols = document.querySelectorAll('.col-8 .col-4');
cols.forEach(function(col) {
    var c = document.querySelector('template').content.cloneNode(true);
    var item = products[Math.floor(Math.random()*3)];

    var title = c.querySelector('.product-title');
    title.textContent += item['title'];

    var price = c.querySelector('.product-price');
    price.textContent += item['price'];

    var image = c.querySelector('.product-image img');
    image.setAttribute('src', item['image']);

    var link = c.querySelector('.product-link');
    link.setAttribute('href', item['link']);

    
    col.append(c);
});

document.querySelectorAll('.product').forEach(element => {element.addEventListener('click', toProduct)});

function toProduct(){
    var link = this.querySelector('.product-link').getAttribute('href');
    window.location.href = link;
}

//menu catalog
document.querySelectorAll('.product-list label').forEach(function(element) {
    element.addEventListener('click', toggleClass);
})
function toggleClass() {
    const selector = this.getAttribute('for');
    var thisLabel = document.querySelector('.product-list label.active');
    thisLabel ? (thisLabel.classList.remove('active') ?? { }) : {};
    
    var label = document.querySelector(".product-list label[for='" + selector + "']");
    if(label != thisLabel)
        label.classList.add('active');
    
    var ul = document.querySelector('.dropdown-list:not(.d-none)');
    ul ? ul.classList.toggle('d-none') : {};
    
    var element = document.getElementById(selector);
    if(element == ul)
        return;
    element.classList.toggle('d-none');
}

// product slider
document.querySelectorAll('.switch-catalog label').forEach(function(element) {
    element.addEventListener('click', show);
});

function show () {
    document.querySelector('.catalog:not(.d-none)').classList.toggle('d-none');

    const value = this.getAttribute('data');
    const selector = ".catalog[value='"+value+"']";
    const element = document.querySelector(selector);
    element.classList.remove('d-none');
}

// slider
document.querySelectorAll('.switch-btn, .carousel-next, .carousel-prev').forEach(function(element) {
    element.addEventListener('click', switchImage);
})

const interval = Number(document.getElementById('carouselExampleFade').getAttribute('data-interval'));
let timeOut_id;
function switchImage (mode = '') {
    clearTimeout(timeOut_id);

     mode = mode == 'next' ? mode : this.getAttribute('data-slide');
    const active_btn = document.querySelector('.switch-btn.active');
            
    const images = document.querySelector('.carousel-inner');
    const active = images.querySelector('.carousel-item.active');
    const count = images.childElementCount;
    
    switch(mode) {
        case 'next':
            //next image
            active.classList.remove('active');
            var active_number = Number(active.getAttribute('slide'));
            var next = (active_number + 1) == count ? 0 : (active_number + 1)
            images.querySelector("[slide='" + next + "']").classList.add('active');

            active_btn.classList.remove('active');

            var new_active_btn = document.querySelector(".switch-btn[data-slide='" + next + "']");
            new_active_btn.classList.add('active');
            break;
        case 'prev':
            //prev image
            active.classList.remove('active');
            var active_number = Number(active.getAttribute('slide'));
            var prev = (active_number - 1) == -1 ? count - 1 : (active_number - 1)
            images.querySelector("[slide='" + prev + "']").classList.add('active');

            active_btn.classList.remove('active');

            var new_active_btn = document.querySelector(".switch-btn[data-slide='" + prev + "']");
            new_active_btn.classList.add('active');
            break;
        default:
            //buttons
            active.classList.remove('active');
            images.querySelector("[slide='" + mode + "']").classList.add('active');

            active_btn.classList.remove('active');

            var new_active_btn = document.querySelector(".switch-btn[data-slide='" + mode + "']");
            new_active_btn.classList.add('active'); 
            break;
    }
    timeOut_id = setTimeout(switchImage, interval, 'next');
}

timeOut_id = setTimeout(switchImage, interval, 'next');