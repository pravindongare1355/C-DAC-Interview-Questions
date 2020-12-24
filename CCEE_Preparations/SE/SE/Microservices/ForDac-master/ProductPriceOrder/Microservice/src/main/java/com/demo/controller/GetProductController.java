package com.demo.controller;

import java.util.List;
import java.util.Optional;
import java.util.ArrayList;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.morningstar.entity.Product;
import com.morningstar.model.ProductDetail;
import com.morningstar.repository.ProductRepository;
import com.morningstar.service.ProductService;
@RestController

public class GetProductController {
@Autowired ProductService productService;
	
	
	@GetMapping("/api/v1.0/product/fetch/item/detail")
	public ResponseEntity<ProductDetail> fetchProductAndPrice(
			@RequestParam(name="productId", defaultValue="0") final Long productId){
		
		if(productId == 0) {
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		
		ProductDetail productDetails = productService.fetchProductDetails(productId);
		
		return new ResponseEntity<ProductDetail>(productDetails, HttpStatus.OK);
	}
	
	
	
	
	
	@GetMapping("/api/v1.0/fetch/product")
	public ResponseEntity<List<Product>> fetchProductList(@RequestParam String category){
		
		try{
			List<Product> productList = productService.fetchProductByCategory(category);
			return new ResponseEntity<List<Product>>(productList, HttpStatus.OK);
		}
		catch (Exception ex) {
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
	}
	
	
	@GetMapping("/api/v1.0/product/fetch/item")
	public ResponseEntity<Product> fetchProductItem(@RequestParam final Long productId){
		
		Product product = productService.fetchProductById(productId);
		
		return new ResponseEntity<Product>(product, HttpStatus.OK);
	}
	
	
	@GetMapping("/")
	public String dummy() {
		
		return "Product service up and running...";
	}
}