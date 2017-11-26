function randomBin() {
    let max = 1;
    let min = 0;

    return Math.floor(
        Math.random() * (max-min + 1)
    );
}    
for(let i = 0; i<101; i++){
    let div = document.createElement('div');
    document.querySelector('.row').appendChild(div);
}

function randomRow(rowDiv) {
    for(let i = 0; i < rowDiv.childNodes.length; i++){
        let div = rowDiv.childNodes[i];
        div.classList.add(randomBin() ? 'active' : 'inactive')
    }  
}

randomRow(document.querySelector('.row'));
function dupRow(){
    let allRows = document.querySelectorAll('.row');
    let lastRow = allRows[allRows.length -1];
    let clone = lastRow.cloneNode(true);
    document.querySelector('.automaton').appendChild(clone);
    procRow(clone, lastRow)
}


function procRow(rowDiv, parentRowDiv){
    for(let i = 0; i < rowDiv.childNodes.length; i++){
        let target = rowDiv.childNodes[i];
        let prevSelf = parentRowDiv.childNodes[i];
        let leftSib = prevSelf.previousElementSibling || 
            parentRowDiv.childNodes[
                parentRowDiv.childNodes.length -1];
        let rightSib = prevSelf.nextElementSibling || 
            parentRowDiv.childNodes[0];
        
        let x = setActiveIfMatchesRule
            .bind(null, target, leftSib, prevSelf, rightSib);
        // x([1, 1, 1], false);
        // x([1, 1, 0], true);
        // x([1, 0, 1], false);
        // x([1, 0, 0], false);
        // x([0, 1, 1], true);
        // x([0, 1, 0], false);
        // x([0, 0, 1], false);
        // x([0, 0, 0], true);
        x([1, 1, 1], true);
        x([1, 1, 0], false);
        x([1, 0, 1], false);
        x([1, 0, 0], true);
        x([0, 1, 1], false);
        x([0, 1, 0], false);
        x([0, 0, 1], true);
        x([0, 0, 0], false);
        
        // first rule

        // if ( 
        //     isActive(leftSib) && 
        //     isActive(prevSelf) &&
        //     isActive(rightSib)
        // ){
        //     setIsActive(target, false);
        // } else if (
        //     isActive(leftSib) &&
        //     isActive(prevSelf) &&
        //     !isActive(rightSib)
        // ){
        //         setIsActive(target,true);
        //     } else if (
        //         isActive(leftSib) && 
        //         !isActive(prevSelf) &&
        //         isActive(rightSib)
        //     )
        //     {
        //         setIsActive(target,false);
        //     }
        
    }
}

function state(cellDiv){
    return cellDiv.classList.contains('active') ? 1: 0;
}

function setIsActive(cellDiv, isActive){
    if(!!isActive){
        cellDiv.classList.remove('inactive');
        cellDiv.classList.add('active')
    } else {
        cellDiv.classList.remove('active');
        cellDiv.classList.add('inactive');
    }
}

function setActiveIfMatchesRule(
    target, 
    leftSib,
    prevSelf,
    rightSib, 
    rule,
    ruleValue
){
    let matchesRule = 
        state(leftSib) === rule[0] &&
        state(prevSelf) === rule[1] &&
        state(rightSib) === rule[2];
    if(matchesRule){
        setIsActive(target,ruleValue);
    }
}

setInterval(dupRow, 50);