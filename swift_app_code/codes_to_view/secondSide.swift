//
//  secondSide.swift
//  projectVr1
//
//  Created by Rie Ruash on 18/02/2021.
//

import SwiftUI

struct GridStack2<Content: View>: View{
    let rows: Int
    let columns: Int
    let content: (Int, Int) -> Content
    
    var body: some View {
        VStack {
            ForEach(0..<rows, id: \.self) { row in
                HStack {
                    ForEach(0..<self.columns, id: \.self) { column in
                        self.content(row, column)
                    }
                }
            }
        }
    }
    
}

struct secondSide: View {
    @State private var squars2 = ["r","r","r","r","r","r","r","r","r"]
    var body: some View {
        //NavigationView {
            VStack {
                ZStack{
                    Image("background2")
                        .resizable()
                        .edgesIgnoringSafeArea(.all)
                    VStack{
                        
                        Spacer()
                        Text("Please choose the \ncolors for the second side:")
                            .font(.title)
                            .foregroundColor(Color.white)
                            
                            .bold()
                            .multilineTextAlignment(.center)
                        Spacer()
                        
                        Spacer()
                        //Spacer()
                        //Spacer()
                        
                        GridStack2(rows: 3, columns: 3) { row, col in
                            //private
                            //private var button_color = squars1[row + col]
                            Button(action: {
                                //Same code using switch
                                switch self.squars2[row*3 + col] {
                                case "y":
                                    self.squars2[row*3 + col] = "b"
                                case "b":
                                    self.squars2[row*3 + col] = "g"
                                case "g":
                                    self.squars2[row*3 + col] = "o"
                                case "o":
                                    self.squars2[row*3 + col] = "w"
                                case "w":
                                    self.squars2[row*3 + col] = "r"
                                default:
                                    self.squars2[row*3 + col] = "y"
                                }
                                
                                //print(self.squars2[row*3 + col])
                            }){
                                Spacer()
                                /*Image("yellow_s")
                                    .resizable()
                                    .aspectRatio(1, contentMode: .fit)
                                    .aspectRatio(contentMode: .fit)
                                    .aspectRatio(contentMode: .fit)
                                    .aspectRatio(contentMode: .fit)
                                    .aspectRatio(contentMode: .fit)
                                    .border(Color.black, width: 2)*/
                                switch self.squars2[row*3 + col] {
                                case "y":
                                    Color.yellow
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "b":
                                    Color.blue
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "g":
                                    Color.green
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "o":
                                    Color.orange
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                case "w":
                                    Color.white
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                default:
                                    Color.red
                                        .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                        .padding(5.0)
                                }
                                //Color.yellow
                                    
                                    //.padding(8)
                                    //Spacer()
                                    //.fixedSize(horizontal: Bool, vertical: <#T##Bool#>)
                                    //.border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: 3)
                                    //.padding(5.0)
                                    
                                    //.frame(width: 3, height: 5, alignment: //Alignment)

                                
                                    /*.fontWeight(.bold)
                                    //.font(.title)
                                    .padding()
                                    .background(Color.white)
                                    .foregroundColor(.black)
                                    //.padding()
                                    .border(Color.white, width: 5)*/
                                Spacer()
                            }
                                }
                        Spacer()
                        //Spacer()
                        //Spacer()
                        //Spacer()
                        
                        //Spacer()
                        Spacer()
                        
                        NavigationLink(destination: thirdSide()){
                                Text("Click to Continue")
                                    .fontWeight(.bold)
                                    .font(.title)
                                    .padding()
                                    .background(Color.white)
                                    .foregroundColor(.black)
                                    .padding(10)
                                    .border(Color.white, width: 2)
                        }
                    }
                }
            }.navigationBarTitle(Text("Second Side"))
        }
    //}
}

struct secondSide_Previews: PreviewProvider {
    static var previews: some View {
        secondSide()
    }
}
