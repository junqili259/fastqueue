//
//  main.swift
//  FastQueue
//
//  Created by Jun Qi Li on 3/6/20.
//  Copyright © 2020 Jun Qi Li. All rights reserved.
//

import Foundation

//  Acts similar to a queue
//  Auto resizes itself 
class FastQueue<Element>:Collection {
    
    
    
    //typealias FastQueueType = Array<Element>
    typealias Element = Array<Element>.Element
    typealias Index = Array<Element>.Index
    
    //  Array container as underlying structure
    var contains = Array<Element>()
    
    //  @startIndex - 1st element in the fastqueue
    //  @endIndex - last element in the fastqueue
    //  @count - # of elements in the fastqueue
    var startIndex: Array<Element>.Index {return contains.startIndex}
    var endIndex: Array<Element>.Index {return contains.endIndex}
    var count: Int {return contains.count}
    
    
    
    //  returns element from user defined postion
    subscript(position: Array<Element>.Index) -> Element {
        return contains[position]
    }
    
    func index(after i: Array<Element>.Index) -> Array<Element>.Index {
        return contains.index(after: i)
    }
    
    
    
}




