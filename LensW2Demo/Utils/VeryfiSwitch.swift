//
//  VeryfiSwitch.swift
//  LensW2Demo
//
//  Created by Bernardo Restrepo on 12/03/22.
//

import UIKit

class VeryfiSwitch: UISwitch {
    var key: String?
    var indexPath: IndexPath?
    convenience init(key: String, indexPath: IndexPath) {
        self.init()
        self.key = key
        self.indexPath = indexPath
    }
}
