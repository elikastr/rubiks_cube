//
//  ContentView.swift
//  projectVr1
//
//  Created by Rie Ruash on 18/02/2021.
//

import SwiftUI

struct ContentView: View {
    private var colors_s = ["y","g","o","b","w","r"]
    //@State public var squars1 = ["y","y","y","y","y","y","y","y","y"]
    @State private var squars2 = ["g","g","g","g","g","g","g","g","g"]
    @State private var squars3 = ["r","r","r","r","r","r","r","r","r"]
    @State private var squars4 = ["b","b","b","b","b","b","b","b","b"]
    @State private var squars5 = ["w","w","w","w","w","w","w","w","w"]
    @State private var squars6 = ["o","o","o","o","o","o","o","o","o"]
    
    var body: some View {
        NavigationView {
            VStack {
                ZStack{
                    Image("background2")
                        .resizable()
                        .edgesIgnoringSafeArea(.all)
                    VStack{
                        Spacer()
                        Spacer()
                        Spacer()
                        Text("Solving Rubik's Cube\n")
                                    .font(.largeTitle)
                                    .foregroundColor(Color.white)
                                    .bold()
                        Text("# like_a_pro")
                            .font(.largeTitle)
                            .fontWeight(.light)
                            .foregroundColor(Color.white)
                            .bold()
                        Spacer()
                        Spacer()
                        HStack{
                            Image("cube-YOB")
                                .resizable()
                                .aspectRatio(1, contentMode: .fit)
                                .aspectRatio(contentMode: .fit)
                                .aspectRatio(contentMode: .fit)
                                .aspectRatio(contentMode: .fit)
                                .aspectRatio(contentMode: .fit)
                            
                        }
                        Spacer()
                        NavigationLink(destination: firstSide()){
                            Text("Click to Start")
                                .fontWeight(.bold)
                                .font(.title)
                                .padding()
                                .background(Color.white)
                                .foregroundColor(.black)
                                .padding(10)
                                .border(Color.white, width: 5)
                        }
                        /*Button(action: {
                            print("hello - main screen\n")
                        }){
                            Text("Click to Start")
                                .fontWeight(.bold)
                                .font(.title)
                                .padding()
                                .background(Color.white)
                                .foregroundColor(.black)
                                .padding(10)
                                .border(Color.white, width: 5)
                        }*/
                        
                    }
                }
            }
        }
    }
}


struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
