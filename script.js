var cols = document.querySelectorAll('.col-8 .col-12');
cols.forEach(function(col) {
    var c = document.querySelector('template').content.cloneNode(true);
    col.append(c);
});


function  toggleClass(ul) {
    var elements = document.querySelectorAll('ul');

    elements.forEach(function(e) {
        if(!e.classList.contains('d-none')) {
            e.classList.add('d-none');
        }
    })

    var element = document.getElementById(ul);
    element.classList.toggle("d-none");
}