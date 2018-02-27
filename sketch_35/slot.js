const Child = {
    template:'#childarea'
};

new Vue({
    el:'#slot',
    components: {
        appChild: Child
    }
});