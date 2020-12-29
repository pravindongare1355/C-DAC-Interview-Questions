package com.demo.controller;
import java.util.List;
import java.util.Optional;
import java.util.ArrayList;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import com.morningstar.entity.Price;
import com.morningstar.entity.Product;
import com.morningstar.repository.PriceRepository;

@RestController
public class GetPriceController {
	@Autowired
	private PriceRepository priceRepo;
	
	@GetMapping("/api/v1.0/price/get/all")
	public ResponseEntity<List<Price>> getAllPrices() {
		List<Price> priceList = priceRepo.findAll();

		if (priceList != null && priceList.size() != 0) {
			return new ResponseEntity<List<Price>>(priceList, HttpStatus.OK);
		}
		return new ResponseEntity<List<Price>>(priceList, HttpStatus.NOT_FOUND);
	}
	
	@GetMapping("api/getPrice/{priceId}")
	public ResponseEntity<Price> getProductById(@PathVariable("priceId") Long id){
		//Long prodId = Long.valueOf(id);
		Optional<Price> optional = priceRepo.findById(id);
		System.out.println(id);
		Price price = optional.orElse(new Price());
		return new ResponseEntity<Price>(price, HttpStatus.OK);
	}
}
