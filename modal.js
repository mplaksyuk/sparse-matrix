// modal
document.querySelectorAll('.btn-open-modal, .btn-close, .btn-send, .modal-background ').forEach(function(element) {
    element.addEventListener('click', showModal);
})

function showModal (){ 
    document.querySelector('.modal').classList.toggle('d-none');
    document.querySelector('body').classList.toggle('overflow-hidden');
};