//SPDX-License-Identifier:MIT
//Software Package Data Exchange

pragma solidity ^0.8.26;

contract calculator{
    uint256 result=0;

    function add(uint256 num) public{
        result +=num;

    }
    function sub(uint256 num)public{
        result-=num;
    }

    function mul(uint256 num)public{
        result*=num;
    }

    function get()public view  returns (uint256){
        return result;
    }
}